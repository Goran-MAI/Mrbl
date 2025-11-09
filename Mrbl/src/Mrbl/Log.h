#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

// Git: https://github.com/gabime/spdlog

namespace Mrbl {

	class MRBL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define MRBL_CORE_TRACE(...)    :: Mrbl::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MRBL_CORE_INFO(...)     :: Mrbl::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MRBL_CORE_WARN(...)     :: Mrbl::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MRBL_CORE_ERROR(...)    :: Mrbl::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MRBL_CORE_FATAL(...)    :: Mrbl::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MRBL_TRACE(...)         :: Mrbl::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MRBL_INFO(...)          :: Mrbl::Log::GetClientLogger()->info(__VA_ARGS__)
#define MRBL_WARN(...)          :: Mrbl::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MRBL_ERROR(...)         :: Mrbl::Log::GetClientLogger()->error(__VA_ARGS__)
#define MRBL_FATAL(...)         :: Mrbl::Log::GetClientLogger()->fatal(__VA_ARGS__)