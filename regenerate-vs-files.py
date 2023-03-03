import json
import os
import subprocess
from shutil import rmtree

def load_config(root_path):
    config_path = os.path.join(root_path, 'config.json')

    if os.path.isfile(config_path):
        with open(config_path) as config_file:
            return json.load(config_file)
    else:
        print('Failed to find config.json file')
        return {}

def replace_tabs_in_file(file_path):
    with open(file_path, 'r+') as file:
        contents = ""
    
        for line in file:
            contents += line.replace('\t', '    ')
    
        file.seek(0)
        file.truncate()
        file.write(contents)

def replace_tabs_in_directory(root_path):
    source_path = os.path.join(root_path, 'Source')

    if os.path.isdir(source_path):
        for root, subdirs, files in os.walk(source_path):
            for file in files:
                file_path = os.path.join(root, file)
                file_ext = os.path.splitext(file)[1]

                if file_ext == '.h' or file_ext == '.cpp':
                    replace_tabs_in_file(file_path)

def delete_build_files(directory_path, config_map):
    project_name = config_map['projectName']
    sln_path = os.path.join(directory_path, project_name + '.sln')
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

def run_unreal_version_selector(root_path, config_map):
    project_name = config_map['projectName']
    project_path = os.path.join(root_path, project_name + '.uproject')
    unreal_vs_path = config_map['unrealVersionSelectorPath']

    if not os.path.isfile(project_path):
        print('.uproject file not found')
        return

    if not os.path.isfile(unreal_vs_path):
        print('Unreal Version Selector not found')
        return

    subprocess.call([
        unreal_vs_path,
        '/projectfiles',
        project_path
    ])

def run_unreal_build_tool(root_path, config_map):
    project_name = config_map['projectName']
    project_path = os.path.join(root_path, project_name + '.uproject')
    unreal_bt_path = config_map['unrealBuildToolPath']

    if not os.path.isfile(project_path):
        print('.uproject file not found')
        return

    if not os.path.isfile(unreal_bt_path):
        print('Unreal Build Tool not found')
        return

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

root_path = os.path.dirname(os.path.abspath(__file__))
config_map = load_config(root_path)

if config_map['replaceTabs']:
    replace_tabs_in_directory(root_path)

delete_build_files(root_path, config_map)
run_unreal_version_selector(root_path, config_map)
run_unreal_build_tool(root_path, config_map)
