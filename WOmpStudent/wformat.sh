#!/bin/bash

set -e
set -u

# ------------------
# Mandatory 
# ------------------

#use this script from the root of your workspace

# ---------------------------------------------------------------------
# main
# ---------------------------------------------------------------------

 find . -not -path "*/INC_SYMLINK/*" -not -path "*/RELEASE/*" -not -path "*/BUILDER/*" -not -path "*/.vscode/*" -regex '.*\.\(cpp\|hpp\|h\|cu\|cuh\|cu\.h\)' -exec clang-format -i {} +
 
# ------------------
# TIPS 
# ------------------

# -exec  : Processes the output files found by the 'find' command using clang-format
# -i     : Inplace (modifies and saves the files directly)
# {}     : Placeholder replaced by the path of each file found
# +      : Optimization: bundles all files into a single clang-format call instead of spawning multiple processes

 
# ---------------------------------------------------------------------
# end
# ---------------------------------------------------------------------


