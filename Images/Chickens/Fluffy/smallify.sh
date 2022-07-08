for png in *small.png
do

    echo "$png"
    magick "$png" -resize "50%" "$png"

done
