import os
import subprocess
from shutil import rmtree

def replace_tabs_in_file(file_path):
    with open(file_path, 'r+') as file:
        contents = ""
    
        for line in file:
            contents += line.replace('\t', '    ')
    
        file.seek(0)
        file.truncate()
        file.write(contents)

def replace_tabs_in_directory(directory_path):
    if os.path.isdir(directory_path):
        for root, subdirs, files in os.walk(directory_path):
            for file in files:
                file_path = os.path.join(root, file)
                file_ext = os.path.splitext(file)[1]

                if file_ext == '.h' or file_ext == '.cpp':
                    replace_tabs_in_file(file_path)

def delete_build_files(directory_path):
    sln_path = os.path.join(directory_path, 'UnrealJordaka.sln')
    vs_path = os.path.join(directory_path, '.vs')
    binaries_path = os.path.join(directory_path, 'Binaries')
    intermediate_path = os.path.join(directory_path, 'Intermediate')
    derived_path = os.path.join(directory_path, 'DerivedDataCache')

    if os.path.isfile(sln_path):
        os.remove(sln_path)
    if os.path.isdir(vs_path):
        rmtree(vs_path)
    if os.path.isdir(binaries_path):
        rmtree(binaries_path)
    if os.path.isdir(intermediate_path):
        rmtree(intermediate_path)
    if os.path.isdir(derived_path):
        rmtree(derived_path)

root_path = os.path.dirname(os.path.abspath(__file__))
source_path = os.path.join(root_path, 'Source')
unreal_vs_path = 'C:\\Program Files (x86)\\Epic Games\\Launcher\\Engine\\Binaries\\Win64\\UnrealVersionSelector.exe'
unreal_bt_path = 'C:\\Program Files\\Epic Games\\UE_5.0\\Engine\\Binaries\\DotNET\\UnrealBuildTool\\UnrealBuildTool.exe'

replace_tabs_in_directory(source_path)
delete_build_files(root_path)

project_path = os.path.join(root_path, 'UnrealJordaka.uproject')
subprocess.call([
    unreal_vs_path,
    '/projectfiles',
    project_path
])
subprocess.call([
    unreal_bt_path,
    'Development',
    'Win64',
    '-Project=' + project_path,
    '-TargetType=Editor',
    '-Progress',
    '-NoEngineChanges',
    '-NoHotReloadFromIDE'
])
