Set (
    SOURCES
    pa_basics.cpp
    container/entitycontainer.cpp
    container/world.cpp
    container/puid.cpp
    interface/terminal.cpp
    interface/cursor.cpp
    interface/interface.cpp
    container/puid.cpp
    surface.cpp
    terrain.cpp
    entity.cpp
    wall.cpp
    item.cpp
    material.cpp
    tree.cpp
    woodlog.cpp
    creature.cpp
    race/humanoid.cpp
    race/human.cpp
    race/orc.cpp
    race/elf.cpp
    pa_engine.cpp
    main.cpp
)

ADD_EXECUTABLE(
    ../pandora main.cpp
    ${SOURCES}
)

