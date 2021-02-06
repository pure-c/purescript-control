default: main
.PHONY: default

USE_GC=1

include $(PUREC_DIR)/mk/target.mk

main: .spago

$(eval $(call purs_mk_target,main,Test.Main,src test))

check: main_leakcheck
