import re

from conans import ConanFile, CMake, tools
from pathlib import Path

required_conan_version = ">=1.45.0"

class GameDevKit(ConanFile):
    name = "gamedevkit"
    author = "Eugene Kuznetsov"
    license = "Mozilla Public License Version 2.0"
    description = "A toolkit with infrastructure for OpenGL game development"
    url = "git@github.com:EugeneKuznetsov/gamedevkit.git"
    scm = {"type": "git", "url": "auto", "revision": "auto"}
    default_user = "gamedev"
    default_channel = "stable"
    generators = "cmake_find_package"
    settings = "os", "compiler", "arch", "build_type"
    tool_requires = "cmake/[>3.20.x]", "ninja/[^1.11.x]", "gtest/[~1.11.x]"
    requires = "glfwcxx/[^1.x]@gamedev/stable", "glew/[^2.2.x]"

    def __init__(self, output, runner, display_name="", user=None, channel=None):
        super().__init__(output, runner, display_name=display_name, user=user, channel=channel)
        self.version = self.read_version()

    def read_version(self):
        cmakelists_txt = Path(self.recipe_folder) / "CMakeLists.txt"
        if cmakelists_txt.exists():
            content = tools.load(cmakelists_txt)
            version_regex = "project[\S\s]*VERSION[\S\s](\d+\.\d+\.\d+)"
            return re.findall(version_regex, content, re.MULTILINE)[0]
        return None

    def build(self):
        if self.should_build is True:
            self.cmake.build()
        if self.should_test is True:
            self.cmake.test(output_on_failure=True)

    def package(self):
        if self.should_install is True:
            self.cmake.install()

    def package_info(self):
        self.cpp_info.names["cmake_find_package"] = "GameDevKit"
        self.add_component(name="Core", libs=["core"], requires=["glfwcxx::glfwcxx", "glew::glew"])
        self.add_component(name="Shaders", libs=["shaders"], requires=["glew::glew"])
        self.clear_external_dependency_include_paths("glfwcxx")
        self.clear_external_dependency_include_paths("glew")

    def add_component(self, name, libs = [], requires = []):
        self.cpp_info.components[name].names["cmake_find_package"] = name
        self.cpp_info.components[name].libs = libs
        self.cpp_info.components[name].requires = requires

    def clear_external_dependency_include_paths(self, dependency):
        for component in self.deps_cpp_info[dependency].components:
            self.deps_cpp_info[dependency].components[component].include_paths.clear()
        self.deps_cpp_info[dependency].include_paths.clear()

    @property
    def cmake(self):
        if not hasattr(self, "_cmake"):
            cmake_modules = [self.source_folder + "/cmake", self.build_folder]
            self._cmake = CMake(self, generator="Ninja")
            self._cmake.definitions["CMAKE_MODULE_PATH"] = ";".join([f.replace("\\", "/") for f in cmake_modules])
            self._cmake.definitions["CMAKE_EXPORT_COMPILE_COMMANDS"] = True
            if self.should_configure is True:
                self._cmake.configure()
        return self._cmake
