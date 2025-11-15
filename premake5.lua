workspace "Mrbl"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	filter "system:windows"
		buildoptions { "/utf-8" }

	filter { "system:linux or system:macosx" }
		buildoptions { "-finput-charset=UTF-8", "-fexec-charset=UTF-8" }

	filter {}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mrbl"
	location "Mrbl"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mrblpch.h"
	pchsource "Mrbl/src/mrblpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"    
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	

		defines {
			"MRBL_PLATFORM_WINDOWS",
			"MRBL_BUILD_DLL"
		}

		postbuildcommands {
			'echo Copying %{cfg.buildtarget.relpath} to ../bin/' .. outputdir .. '/Tribalion',
			-- Zielordner anlegen (funktioniert auch, wenn er schon existiert)
			('{MKDIR} ../bin/' .. outputdir .. '/Tribalion'),
			-- DLL oder Lib kopieren
			('{COPY} "%{cfg.buildtarget.relpath}" "../bin/' .. outputdir .. '/Tribalion/"')
		}

	filter "configurations:Debug" 
		defines "MRBL_DEBUG"
		symbols "On"


	filter "configurations:Release" 
		defines "MRBL_RELEASE"
		optimize "On"

	filter "configurations:Dist" 
		defines "MRBL_DIST"
		optimize "On"


project "Tribalion"
	location "Tribalion"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Mrbl/vendor/spdlog/include",
		"Mrbl/src"
	}

	links {
		"Mrbl"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"MRBL_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug" 
		defines "MRBL_DEBUG"
		symbols "On"


	filter "configurations:Release" 
		defines "MRBL_RELEASE"
		optimize "On"

	filter "configurations:Dist" 
		defines "MRBL_DIST"
		optimize "On"

