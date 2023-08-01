add_rules("mode.debug", "mode.release")

option("build_sample")
    set_default(false)
    set_showmenu(true)
option_end()

target("simpleocv")
    set_kind("static")
    add_includedirs("include/", { public = true })
    add_files("src/*.cpp")

-- sample
if has_config("build_python") then
    target("simpleocv_basic")
        set_kind("binary")
        add_files("sample/basic.cpp")
        add_defines("IMAGE_PATH=R\"($(curdir)/imgs)\"")
        add_deps("simpleocv")
end
