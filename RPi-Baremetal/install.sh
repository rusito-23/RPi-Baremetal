

DESTINATION=$1

echo "Installing into: ${DESTINATION}"

cp boot/bootcode.bin $DESTINATION/bootcode.bin
cp kernel7.img $DESTINATION/kernel7.img
cp main.elf $DESTINATION/start.elf

echo "Done"
