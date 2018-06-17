FROM epitechcontent/epitest-docker:latest
RUN dnf install SFML -y
RUN ln -s /usr/lib64/libsfml-network.so.2.4 /usr/lib64/libsfml-network.so
RUN ln -s /usr/lib64/libsfml-audio.so.2.4 /usr/lib64/libsfml-audio.so
RUN ln -s /usr/lib64/libsfml-graphics.so.2.4 /usr/lib64/libsfml-graphics.so
RUN ln -s /usr/lib64/libsfml-window.so.2.4 /usr/lib64/libsfml-window.so
RUN ln -s /usr/lib64/libsfml-system.so.2.4 /usr/lib64/libsfml-system.so
ENTRYPOINT ["/bin/bash"]
