FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/skeleton_markers/msg"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/publisher.py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
