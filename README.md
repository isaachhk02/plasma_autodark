# Auto Dark Mode for KDE Plasma 5 and 6

Created by hhk02

This small program changes your current theme depending of the hour of the system.

# Build:
``make``


# Install:
``make install``

#  Start the service:
   ``systemctl --user start autodark.service``

   ``systemctl --user start autodark.timer``


#  Stop the service:
   ``systemctl --user stop autodark.service``

   ``systemctl --user stop autodark.timer``


#  Disable the service on startup:
   ``systemctl --user disable autodark.service``

   ``systemctl --user disable autodark.timer``

#  Enable on start the OS:
   ``systemctl --user enable autodark.service``
   ``systemctl --user enable autodark.timer``

# LIMITS:
-   For the moment can't use custom themes for change
