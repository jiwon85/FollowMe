FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/skeleton_markers/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/skeleton_markers/msg/__init__.py"
  "../src/skeleton_markers/msg/_VictimFinder.py"
  "../src/skeleton_markers/msg/_Skeleton.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
