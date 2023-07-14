add_rules("mode.debug", "mode.release")

set_languages("cxx17")

target("simpleocv")
    set_kind("static")
    add_includedirs("include/", { public = true })
    add_files("src/*.cpp")

-- sample
target("simpleocv-sample")
    set_kind("binary")
    add_files("sample/basic.cpp")
    add_defines("IMAGE_PATH=R\"($(curdir)/imgs)\"")
    add_deps("simpleocv")
