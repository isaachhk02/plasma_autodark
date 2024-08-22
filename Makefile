make:
	g++ autodark.cpp -o autodark $(pkg-config --cflags --libs Qt6Core KF6ConfigCore KF6CoreAddons)

install:
	echo "Copying binary to /usr/bin"
	sudo cp -v autodark /usr/bin
	echo "Copying systemd service to /etc/systemd/user"
	sudo cp -v autodark.service /etc/systemd/user
	sudo cp -v autodark.timer /etc/systemd/user
	echo "Enabling systemd service..."
	systemctl --user daemon-reload
	systemctl --user enable --now autodark.service
	systemctl --user enable --now autodark.timer
	echo "Done!"
