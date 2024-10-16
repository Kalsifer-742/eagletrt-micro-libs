###############################################################################
# Can manager makefile
# Generated by gen_library_template.sh, for more information refer to:
# https://github.com/eagletrt/micro-libs/blob/master/README.md
#
# Generation date: 2024-04-14 19:33:16 +0200
# To use include this file in your Makefile as follows:
#     include path/to/library/root/dir/can-manager.mk
###############################################################################


###############################################################################
### DIRECTORIES                                                             ###
###############################################################################

# Root directory of the library
CAN_MANAGER_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

###############################################################################
### SOURCES                                                                 ###
###############################################################################

# List of all the library sources
CAN_MANAGER_C_SOURCES?=$(shell find $(CAN_MANAGER_DIR)src -name "*.c")

###############################################################################
### HEADERS                                                                 ###
###############################################################################

# List of all the library include directories
CAN_MANAGER_C_INCLUDE_DIRS?=$(shell find $(CAN_MANAGER_DIR)inc -type d)
# List of all the library include directories with the -I prefix
CAN_MANAGER_C_INCLUDE_DIRS_PREFIX?=$(addprefix -I, $(CAN_MANAGER_C_INCLUDE_DIRS))

