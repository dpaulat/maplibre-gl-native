#include <mbgl/platform/gl_functions.hpp>

#include <mbgl/util/logging.hpp>
#include <sstream>

namespace mbgl {
namespace platform {

#if !defined(NDEBUG) || defined(MLN_GL_CHECK_ERRORS)
void glCheckError(const char* cmd, const char* file, int line) {
    if (GLenum err = glGetError()) {
        Log::Warning(Event::OpenGL,
                     "Error" + std::to_string(err) + ": " + cmd + " - " + file + ":" + std::to_string(line));
    }
}
#endif

} // namespace platform
} // namespace mbgl
