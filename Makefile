#
# Small Project Makefile
#
# this file is small a part of build_process package.
# full-featured build_process is available on BSD license
# on http://www.baszerr.org, prjs -> build_process.
#

ifeq (,$(filter %/gen/$(TARGET),$(basename $(CURDIR))))
#
# main part, run in sources dir
#

# don't use Verbose mode (be silent)?
ifeq (,$V)
MFLAGS+=-s
endif

define run-in-gen
	@echo
	@echo "##### build $@"
	mkdir -p `find . -type d | grep -v './\.' | \
	          grep -v '^\./gen/' | grep -v '^\./gen$$' | \
			  grep -v '^\.$$' | sed 's:^\./:$(GENDIR)/$@/:'`
	+$(MAKE) $(MFLAGS) -C "$(GENDIR)/$@" -f "$(CURDIR)/Makefile" \
		TARGET=$@ $(TARGET)
endef

.SUFFIXES:

# use user-provided configuration
include config.mk

GENDIR:=$(CURDIR)/gen
SRCDIR:=$(CURDIR)
VPATH+=$(SRCDIR)
export GENDIR SRCDIR VPATH


CXXSRCS_NOMAIN:=$(shell find . -iname '*.cpp' -exec grep -L '^int main' {} \; )
CSRCS_NOMAIN  :=$(shell find . -iname '*.c'   -exec grep -L '^int main' {} \; )
export CSRCS_NOMAIN CXXSRCS_NOMAIN
CXXTESTSRCS:=$(shell find . -iname '*.t.cpp')
CTESTSRCS  :=$(shell find . -iname '*.t.c'  )
export CTESTSRCS CXXTESTSRCS

CXXSRCS:=$(filter-out $(CXXTESTSRCS), $(shell find . -iname '*.cpp'))
CSRCS  :=$(filter-out $(CTESTSRCS),   $(shell find . -iname '*.c'  ))
export CSRCS CXXSRCS

COMMON_FLAGS:=-Wall -I$(SRCDIR)

CFLAGS+=$(COMMON_FLAGS)
export CFLAGS

CXXFLAGS+=$(COMMON_FLAGS)
export CXXFLAGS

LDFLAGS+=
export LDFLAGS

export TARGET

TEST_PROGRAM_NAME=$(PROGRAM_NAME).t
export TEST_PROGRAM_NAME

.PHONY: all
all: debug

.PHONY: debug
debug: CFLAGS+=-g3
debug: CXXFLAGS+=-g3
debug: TARGET:=all
debug:
	@$(run-in-gen)

.PHONY: release
release: CFLAGS+=-O3 -DNDEBUG
release: CXXFLAGS+=-O3 -DNDEBUG
release: TARGET:=all
release:
	@$(run-in-gen)

.PHONY: profile
profile: CFLAGS+=-pg -DNDEBUG -O3 -g
profile: CXXFLAGS+=-pg -DNDEBUG -O3 -g
profile: LDFLAGS+=-pg
profile: TARGET:=all
profile:
	@$(run-in-gen)

.PHONY: test
test: CFLAGS+=-g3
test: CXXFLAGS+=-g3
test: TARGET:=test
test:
	@$(run-in-gen)

.PHONY: clean
clean:
	@echo
	@echo "##### clean"
	rm -rvf "$(GENDIR)"

else
#
# part run in gen
#

# object files:
COBJS  +=$(CSRCS:.c=.o)
CXXOBJS+=$(CXXSRCS:.cpp=.o)
# obj files without 'main()':
COBJS_NOMAIN  +=$(CSRCS_NOMAIN:.c=.o)
CXXOBJS_NOMAIN+=$(CXXSRCS_NOMAIN:.cpp=.o)
# test object files:
CTESTOBJS  +=$(CTESTSRCS:.c=.o)
CXXTESTOBJS+=$(CXXTESTSRCS:.cpp=.o)

# dep files:
CDEPS  +=$(CSRCS:.c=.d)     $(CTESTSRCS:.c=.d)
CXXDEPS+=$(CXXSRCS:.cpp=.d) $(CXXTESTSRCS:.cpp=.d)


.PHONY: all
all: $(PROGRAM_NAME)

.PHONY: test
test: $(TEST_PROGRAM_NAME)

$(TEST_PROGRAM_NAME): $(CXXTESTOBJS) $(CTESTOBJS) \
						$(CXXOBJS_NOMAIN) $(COBJS_NOMAIN)
	echo "LD  $@"
	$(LD) $(LDFLAGS) -o $@ $^

$(PROGRAM_NAME): $(CXXOBJS) $(COBJS)
	echo "LD  $@"
	$(LD) $(LDFLAGS) -o $@ $^

# C++ source files:
%.o: %.cpp $(SRCDIR)/Makefile
	echo "CXX $*.cpp"
	$(CXX) $(CXXFLAGS) -MMD -c "$(SRCDIR)/$*.cpp" -o "$@"

# C source files:
%.o: %.c $(SRCDIR)/Makefile
	echo "CC  $*.c"
	$(CC) $(CFLAGS) -MMD -c "$(SRCDIR)/$*.c" -o "$@"


# makefile depends on its include
$(SRCDIR)/Makefile: $(SRCDIR)/config.mk
	touch "$@"


# has C sources?
-include $(CDEPS)

# has C++ sources?
-include $(CXXDEPS)

endif
