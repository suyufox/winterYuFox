#!/usr/bin/env python3
import argparse
import subprocess
import sys
import os
from script import command

def env():
    print("Running environment checks... | 执行环境检查")
    command.env_cmake_check()
    print("\n")
    command.env_llvm_check()
    sys.exit(0)

def build(target: str, framework: str):
    print(f"Building for target: {target}, architecture: {framework}")

def run_cmake_generate(project, output):
    print("---------------------------------------------------")
    try:
        result = subprocess.run(["cmake", "-G", project, "-B", output],
                              check=True,
                              capture_output=True,
                              text=True)
        print(f"CMake Generate Output:\n{result.stdout}")
    except subprocess.CalledProcessError as e:
        print(f"CMake Generate Error:\n{e.stderr}")
        raise RuntimeError("CMake generation failed") from e
    except FileNotFoundError:
        raise RuntimeError("CMake not found. Please install CMake and add it to PATH")

def run_cmake_build(output, config, parallel):
    print("---------------------------------------------------")
    try:
        result = subprocess.run(["cmake", "--build", output, "--config", config, "--parallel", parallel],
                              check=True,
                              capture_output=True,
                              text=True)
        print(f"Build Output:\n{result.stdout}")
    except subprocess.CalledProcessError as e:
        print(f"Build Error:\n{e.stderr}")
        raise RuntimeError("Build failed") from e

def run_executable(executable_path):
    print("---------------------------------------------------")
    print("Running...")
    try:
        if sys.platform == "win32":
            executable_path = executable_path.replace("/", "\\")
            os.system(executable_path)
        else:
            os.system(executable_path)
    except Exception as e:
        raise RuntimeError(f"Failed to run executable: {e}")

def run(target: str,arch: str,framework: str,project: str,output: str,parallel: int):
    print(f"Building for target: {target}, architecture: {arch}")
    print(f"framework: {framework}, projecr: {project}")
    print(f"outpot: {output}, parallel: {parallel}")
    print("---------------------------------------------------")
    
    executable = './publish/x64/bin/debug64/winteryufox'

    try:
        run_cmake_generate(project, output)
        run_cmake_build(output, target, parallel)
        run_executable(executable)
    except RuntimeError as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)
    

def main():
    # 主解析器
    parser = argparse.ArgumentParser(description='Build script | 构建脚本')
    subparsers = parser.add_subparsers(dest='command', help='Subcommand help | 子命令帮助')

    # env 子命令
    env_parser = subparsers.add_parser('env', help='Environmental monitoring | 环境检测')

    # build 子命令
    build_parser = subparsers.add_parser('build', help='Build project | 构建项目')
    build_parser.add_argument('--target',       choices=['debug', 'release'],           default='debug')
    build_parser.add_argument('--framework',    choices=['desktop', 'android', 'ios'],  default='desktop')

    run_parser = subparsers.add_parser("run", help='Run project | 运行项目')
    run_parser.add_argument('--target',     choices=['debug', 'release'],           default='debug')
    run_parser.add_argument('--arch',       choices=['x86', 'x64'],                 default='x64'  )
    run_parser.add_argument('--framework',  choices=['desktop', 'android', 'ios'],  default='desktop')
    run_parser.add_argument('--project',    choices=['Visual Studio 17 2022','Ninja','Unix Makefiles'], default='Visual Studio 17 2022')
    run_parser.add_argument('--outpot',     type=str, default='build')
    run_parser.add_argument('--parallel',   type=int, default=4)

    args = parser.parse_args()

    # 命令路由
    match args.command :
      case 'env':
        env()

      case 'build':
        build(args.target, args.framework)

      case 'run':
        run(args.target,args.arch,args.framework,args.project,args.outpot,args.parallel)

      case '_':
          parser.print_help()

if __name__ == "__main__":
    main()