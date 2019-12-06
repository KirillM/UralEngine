workspace "Ural"
    architecture "x64"

    configuration
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 project "Ural"
    location "Ural"
    kind "SharedLib"   
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    include
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:mac"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "UL_PLATFORM_MAC",
            "UL_BUILD_DLYB"
        }

        postbuildcommands
        {
            ("cp %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Sandbox")
        }

    filter "configuration:Debug"
        defines "UL_DEBUG"
        symbols "On"
        
    filter "configuration:Release"
        defines "UL_RELEASE"    
        optimize "On"

    filter "configuration:Dist"
        defines "UL_DIST"    
        optimize "On"        

project "Sandbox"        
    location "Sandbox"
    kind "ConsoleApp"   
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    include
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    links
    {
        "Ural"
    }

    filter "system:mac"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "UL_PLATFORM_MAC"
        }

        -- postbuildcommands
        -- {
        --     ("cp %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/Sandbox")
        -- }

    filter "configuration:Debug"
        defines "UL_DEBUG"
        symbols "On"
        
    filter "configuration:Release"
        defines "UL_RELEASE"    
        optimize "On"

    filter "configuration:Dist"
        defines "UL_DIST"    
        optimize "On"       