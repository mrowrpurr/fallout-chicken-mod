YELLOW="#ffcc00"
PINK="#bf1fba"
TOLERANCE="40%"

for png in *.png
do

    echo "$png"
    # magick "$png" -coalesce -fuzz "$TOLERANCE" -fill "$PINK" -opaque "$YELLOW" -layers optimize "pink.$png"
    # magick "pink.$png" -resize "75%" "small.pink.$png"
    magick "$png" -resize "50%" "small.$png"

done
