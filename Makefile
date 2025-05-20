make:
	g++ autodark.cpp -o autodark
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
uninstall:
	echo "Removing binaries"
	sudo rm -v /usr/bin/autodark
	echo "Removing systemd user services"
	sudo rm -v /etc/systemd/user/autodark*
	systemctl --user daemon-reload
	echo "Uninstall done!"
	
