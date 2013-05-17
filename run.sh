#!/bin/bash
echo "Enter the path from / to the xv2 folder. E.G. /root/Desktop/xv2"
read directory
cd $directory/python
nohup python -m SimpleHTTPServer &
python ClientModuleProxyv3.py