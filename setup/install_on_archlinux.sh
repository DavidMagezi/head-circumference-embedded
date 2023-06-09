#/!/bin/bash
echo "Installing libraries necessary for head_circumference_embedded"
echo "This will install libraries and download datasets on a archlinux host for quicker compilation and early testing"
needed_packages=opencv wget unzip
pacman -Q $needed_packages || sudo pacman -S --needed $needed_packages

ultrasound_url=https://zenodo.org/record/1327317/files/
compression_extension='zip'
ultrasound_files="test_set.$compression_extension test_set_pixel_size.csv training_set.$compression_extension training_set_pixel_size_and_HC.csv"
file_list='file_list.txt'
target_dir=/home/${USER}/local/ultrasound
if [ ! -d $target_dir ]; then
    mkdir -p $target_dir
    printf %"s\n" $ultrasound_files &> $target_dir/$file_list
    cd $target_dir
    wget --base=$ultrasound_url --input-file=$file_list
    for compressed_file in $(grep ".$compression_extension$" $file_list); do 
        unzip $compressed_file
    done
fi
