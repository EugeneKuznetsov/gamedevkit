#pragma once

#include <memory>

namespace glfwcxx {
class Core;
}  // namespace glfwcxx

namespace gamedevkit {

class Application::Details {
public:
    Details();

private:
    std::unique_ptr<glfwcxx::Core> glfwcxx_;
};

}  // namespace gamedevkit
