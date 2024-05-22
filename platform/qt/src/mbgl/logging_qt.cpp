#include <mbgl/util/logging.hpp>
#include <mbgl/util/enum.hpp>

#include <unordered_map>

#include <QDebug>

namespace mbgl {

void Log::platformRecord(EventSeverity severity, const std::string &msg) {
    static const std::unordered_map<EventSeverity, QtMsgType> levelMap_{
        {EventSeverity::Debug, QtMsgType::QtDebugMsg},
        {EventSeverity::Info, QtMsgType::QtInfoMsg},
        {EventSeverity::Warning, QtMsgType::QtWarningMsg},
        {EventSeverity::Error, QtMsgType::QtCriticalMsg}};

    static const QMessageLogContext context(nullptr, 0, nullptr, "mbgl");

    QtMsgType msgType = QtMsgType::QtInfoMsg;

    auto it = levelMap_.find(severity);
    if (it != levelMap_.cend()) {
        msgType = it->second;
    }

    qt_message_output(msgType, context, QString::fromStdString(msg));
}

} // namespace mbgl
