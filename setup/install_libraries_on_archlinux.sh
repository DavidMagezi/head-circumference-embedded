#/!/bin/bash
echo "Installing libraries necessary for head_circumference_embedded"
echo "This will install on a archlinux host for quicker compilation and early testing"
needed_packages=opencv
pacman -Q $needed_packages || sudo pacman -S --needed $needed_packages
