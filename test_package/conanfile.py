from conans import ConanFile, CMake
from pathlib import Path

class GDKConsumer(ConanFile):
    generators = "cmake_find_package"
    settings = "os", "compiler", "arch", "build_type"
    tool_requires = "cmake/[>3.20.x]", "ninja/[^1.11.x]"

    def build(self):
        self.cmake.build()

    def test(self):
        gamedevkit_app = self._path_to_binary("gamedevkit_app")
        self.run(gamedevkit_app, run_environment=True)

    def _path_to_binary(self, name):
        binary = str(Path("bin") / name)
        if self.settings.os == "Windows":
            binary += ".exe"
        return binary
    
    @property
    def cmake(self):
        if not hasattr(self, "_cmake"):
            self._cmake = CMake(self, generator="Ninja")
            self._cmake.definitions["CMAKE_EXPORT_COMPILE_COMMANDS"] = True
            self._cmake.configure()
        return self._cmake
