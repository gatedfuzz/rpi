cd build

# quit without confimation
define hook-quit
	set confirm off
end

file app.elf
target remote localhost:3333
load
monitor reset init
echo Running...\n
c
