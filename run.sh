cp /mnt/hgfs/vm_share/finsh/* ./
rm a.out
gcc *.c -Wl,-Ts.lds -lpthread -I./

sleep 1
./a.out
