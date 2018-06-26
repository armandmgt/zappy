set(CORE
        main.cpp
        ../common/cir_buffer.c
        ../common/init_cir_buffer.c
        )

set(GENERATION
        Generation/GuiMapManager.cpp
        )

set(CORE_SCENES
        Scenes/MenuScene.cpp
        Scenes/GameScene.cpp
        )

set(CORE_NETWORK
        Network/Network.cpp
        )

set(SFML_SRCS
        Sfml/App.cpp
        Sfml/Scene.cpp
        )

set(IMGUI_SRCS
        Imgui/imgui.cpp
        Imgui/imgui_draw.cpp
        Imgui/imgui_demo.cpp
        )

set(IMGUI_SFML_SRCS
        Imgui/imgui-sfml/imgui-SFML.cpp
        )

set(SRCS
        ${CORE}
        ${GENERATION}
        ${CORE_SCENES}
        ${CORE_NETWORK}
        ${SFML_SRCS}
        ${IMGUI_SRCS}
        ${IMGUI_SFML_SRCS}
        )