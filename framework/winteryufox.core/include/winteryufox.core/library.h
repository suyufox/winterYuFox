#pragma once

#ifdef WINTERYUFOX_COER_RARY_EXPORTS
#define WINTERYUFOX_COER_API __declspec(dllexport)
#else
#define WINTERYUFOX_COER_API __declspec(dllimport)
#endif

extern "C" {
	WINTERYUFOX_COER_API void sayHello();
}