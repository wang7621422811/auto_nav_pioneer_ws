from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'auto_nav_pioneer_pkg'
setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
        (os.path.join('share', package_name, 'urdf'), glob('urdf/*')),
        (os.path.join('share', package_name, 'worlds'), glob('worlds/*')),
        (os.path.join('share', package_name, 'meshes'),
            glob(os.path.join('meshes', '*.dae')) +
            glob(os.path.join('meshes', '*.stl')) +
            glob(os.path.join('meshes', '*.tga'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Leon',
    maintainer_email='24601787@student.uwa.edu.au',
    description='Pioneer 3-AT autonomous navigation package for AUTO4508',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'safety_teleop_node = auto_nav_pioneer_pkg.teleop.safety_teleop_node:main',
            'waypoint_manager_node = auto_nav_pioneer_pkg.navigation.waypoint_manager_node:main',
            'pure_pursuit_controller_node = auto_nav_pioneer_pkg.navigation.pure_pursuit_controller_node:main',
            'fake_odom_node = auto_nav_pioneer_pkg.utils.fake_odom_node:main',

        ],
    },
)
