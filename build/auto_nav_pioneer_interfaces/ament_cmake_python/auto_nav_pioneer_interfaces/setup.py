from setuptools import find_packages
from setuptools import setup

setup(
    name='auto_nav_pioneer_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('auto_nav_pioneer_interfaces', 'auto_nav_pioneer_interfaces.*')),
)
