import subprocess


def env_cmake_check():
    print("-----------------------------------------------------------")
    print("cmake check | cmake 检查中...")
    print("----------------------------")
    try:
      # 检查cmake是否存在，存在则输出版本信息
        result = subprocess.run(["cmake", "--version"],
                            check=True,
                            capture_output=True,
                            text=True)
        print(f"CMake Test results | 检查结果: \n{result.stdout.splitlines()[0]}")
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        raise RuntimeError("CMake Not installed or not added to the system path | 未安装或未加入系统路径") from e
    print("-----------------------------------------------------------")

def env_llvm_check():
    print("-----------------------------------------------------------")
    print("LLVM check | LLVM 检查中...")
    print("----------------------------")
    try:
        result = subprocess.run(["clang", "--version"],
                            check=True,
                            capture_output=True,
                            text=True)
        print(f"LLVM Test results | 检查结果: \n{result.stdout.splitlines()[0]}")
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        raise RuntimeError("LLVM Not installed or not added to the system path | 未安装或未加入系统路径") from e
    print("-----------------------------------------------------------")

