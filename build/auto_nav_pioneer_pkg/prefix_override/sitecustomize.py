import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/parallels/workspace/auto_nav_pioneer_ws/install/auto_nav_pioneer_pkg'
