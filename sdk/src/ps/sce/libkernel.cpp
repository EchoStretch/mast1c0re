#if (defined(PS4) && PS4) || (defined(PS5) && PS5)
#include <ps/sce/libkernel.hpp>
#include <ps/breakout.hpp>
#include <offsets/ps/eboot/eboot.hpp>

int32_t PS::Sce::Kernel::Usleep(uint32_t microseconds)
{
    return (int32_t)PS::Breakout::call(EBOOT(EBOOT_SCE_KERNEL_USLEEP_STUB), (uint64_t)microseconds);
}

int32_t PS::Sce::Kernel::Sleep(uint32_t seconds)
{
    return PS::Sce::Kernel::Usleep(seconds * 1000000);
}

#ifdef LIBKERNEL
int32_t PS::Sce::Kernel::SendNotificationRequest(int32_t device, PS::Sce::NotificationRequest* request, uint64_t size, int32_t blocking)
{
    return (int32_t)PS::Breakout::call(LIBKERNEL(LIB_KERNEL_SCE_KERNEL_SEND_NOTIFICATION_REQUEST), device, PVAR_TO_NATIVE(request), size, blocking);
}

int32_t PS::Sce::Kernel::LoadStartModule(char* name, size_t argc, void* argv, uint32_t flags, int32_t unk1, int32_t unk2)
{
    return (int32_t)PS::Breakout::call(LIBKERNEL(LIB_KERNEL_SCE_KERNEL_LOAD_START_MODULE), PVAR_TO_NATIVE(name), argc, PVAR_TO_NATIVE(argv), flags, unk1, unk2);
}

int32_t PS::Sce::Kernel::RandomizedPath(char* buffer, int* length)
{
    return (int32_t)PS::Breakout::call(LIBKERNEL(LIB_KERNEL_SCE_KERNEL_RANDOMIZED_PATH), 0, PVAR_TO_NATIVE(buffer), PVAR_TO_NATIVE(length));
}

int32_t PS::Sce::Kernel::Dlsym(int moduleId, char* name, void* destination)
{
    return (int32_t)PS::Breakout::call(LIBKERNEL(LIB_KERNEL_SCE_KERNEL_DLSYM), moduleId, PVAR_TO_NATIVE(name), PVAR_TO_NATIVE(destination));
}
#endif
#endif