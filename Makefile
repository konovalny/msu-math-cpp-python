# RUN MAKE IN ALL SUBDIRECTORIES

SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)

clean: MAKE_TARGET := clean
werror: MAKE_TARGET := werror

clean: $(SUBDIRS)
werror: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKE_TARGET)

.PHONY: all $(SUBDIRS)
