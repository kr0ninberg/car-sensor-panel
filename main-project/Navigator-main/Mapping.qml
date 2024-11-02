import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.6
import QtPositioning 5.6

Item {

    Plugin {
        id: mapPlugin
        name: "osm"

        PluginParameter { name: "osm.mapping.custom.host"; value: "http://tile.thunderforest.com/landscape/%z/%x/%y.png?apikey=aa35b987aee84b5e8aeb03a3db5da454&fake=.png" }
    }

    Map {
        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(55.78083, 37.71134) // Oslo
        zoomLevel: 16
    }
}
