#include <stdlib.h>

extern void goRVExtension(char *output, size_t outputSize, char *input);
extern void goRVExtensionVersion(char *output, size_t outputSize);
extern void goRVExtensionArgs(char* output, size_t outputSize, char* input, char** argv, int argc);

#ifdef WIN64
  void RVExtension(char *output, size_t outputSize, char *input) {
    goRVExtension(output, outputSize, input);
  }

  void RVExtensionVersion(char *output, size_t outputSize) {
    goRVExtensionVersion(output, outputSize);
  }
#elif _WIN32
  __declspec(dllexport) void __stdcall _RVExtension(char *output, size_t outputSize, char *input) {
    goRVExtension(output, outputSize, input);
  }

  __declspec(dllexport) void __stdcall _RVExtensionVersion(char *output, size_t outputSize) {
    goRVExtensionVersion(output, outputSize);
  }
#endif
