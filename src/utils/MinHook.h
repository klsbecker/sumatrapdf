/* Copyright 2020 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

// based on https://github.com/TsudaKageyu/minhook
// only supports 64 bit and all code in a single file

// MinHook Error Codes.
typedef enum MH_STATUS {
    // Unknown error. Should not be returned.
    MH_UNKNOWN = -1,

    // Successful.
    MH_OK = 0,

    // MinHook is already initialized.
    MH_ERROR_ALREADY_INITIALIZED,

    // MinHook is not initialized yet, or already uninitialized.
    MH_ERROR_NOT_INITIALIZED,

    // The hook for the specified target function is already created.
    MH_ERROR_ALREADY_CREATED,

    // The hook for the specified target function is not created yet.
    MH_ERROR_NOT_CREATED,

    // The hook for the specified target function is already enabled.
    MH_ERROR_ENABLED,

    // The hook for the specified target function is not enabled yet, or already
    // disabled.
    MH_ERROR_DISABLED,

    // The specified pointer is invalid. It points the address of non-allocated
    // and/or non-executable region.
    MH_ERROR_NOT_EXECUTABLE,

    // The specified target function cannot be hooked.
    MH_ERROR_UNSUPPORTED_FUNCTION,

    // Failed to allocate memory.
    MH_ERROR_MEMORY_ALLOC,

    // Failed to change the memory protection.
    MH_ERROR_MEMORY_PROTECT,

    // The specified module is not loaded.
    MH_ERROR_MODULE_NOT_FOUND,

    // The specified function is not found.
    MH_ERROR_FUNCTION_NOT_FOUND
} MH_STATUS;

// Can be passed as a parameter to MH_EnableHook, MH_DisableHook,
// MH_QueueEnableHook or MH_QueueDisableHook.
#define MH_ALL_HOOKS NULL

#ifdef __cplusplus
extern "C" {
#endif

MH_STATUS WINAPI MH_Initialize();
MH_STATUS WINAPI MH_Uninitialize();
MH_STATUS WINAPI MH_CreateHook(void* pTarget, void* pDetour, void** ppOriginal);
MH_STATUS WINAPI MH_CreateHookApi(const WCHAR* pszModule, const char* pszProcName, void* pDetour, void** ppOriginal);
MH_STATUS WINAPI MH_CreateHookApiEx(const WCHAR* pszModule, const char* pszProcName, void* pDetour, void** ppOriginal,
                                    void** ppTarget);
MH_STATUS WINAPI MH_RemoveHook(void* pTarget);
MH_STATUS WINAPI MH_EnableHook(void* pTarget);
MH_STATUS WINAPI MH_DisableHook(void* pTarget);
MH_STATUS WINAPI MH_QueueEnableHook(void* pTarget);
MH_STATUS WINAPI MH_QueueDisableHook(void* pTarget);
MH_STATUS WINAPI MH_ApplyQueued();
const char* WINAPI MH_StatusToString(MH_STATUS status);

#ifdef __cplusplus
}
#endif
