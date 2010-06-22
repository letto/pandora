Set (
    SOURCES
    type/pabasics.cpp
    type/pastring.cpp
    type/puid.cpp
    type/humanoid.cpp
    enum/enum.cpp
    enum/color.cpp
    enum/size.cpp
    enum/direction.cpp
    enum/race.cpp
    type/entity.cpp
    type/item.cpp
    type/creature.cpp
    type/surface.cpp
    type/terrain.cpp
    container/entitycontainer.cpp
    container/world.cpp
    interface/terminal.cpp
    interface/cursor.cpp
    interface/interface.cpp
    wall.cpp
    material.cpp
    tree.cpp
    woodlog.cpp
    pa_engine.cpp
    main.cpp
)

ADD_EXECUTABLE(
    ../pandora
    ${SOURCES}
)

