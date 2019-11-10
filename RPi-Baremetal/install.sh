DESTINATION=$1

echo "Compiling .  .  ."

make clean && make

if [ -d "$DESTINATION" ]; then
    echo "Installing into: ${DESTINATION} .  .  ."


    cp boot/bootcode.bin $DESTINATION/bootcode.bin
    cp kernel7.img $DESTINATION/kernel7.img
    cp boot/start.elf $DESTINATION/start.elf

    echo "Files copied"
    echo "Unmounting location: ${DESTINATION} .  .  ."

    diskutil unmount ${DESTINATION}

else
    echo "Error: ${DESTINATION} not found. Can not continue."
    exit 1
fi
