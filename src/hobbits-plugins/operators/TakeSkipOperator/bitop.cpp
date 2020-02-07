#include "bitop.h"
#include "invertop.h"
#include "oneop.h"
#include "reverseop.h"
#include "skipop.h"
#include "takeop.h"
#include "zeroop.h"
#include <QList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

BitOp::BitOp(int value) :
    m_value(value)
{

}

BitOp::~BitOp()
{

}

QList<QSharedPointer<BitOp>> BitOp::parseOps(QString opString)
{
    QRegularExpression re("\\K([stozri](\\*|\\d+))");
    QRegularExpressionMatchIterator match = re.globalMatch(opString);

    QList<QSharedPointer<BitOp>> ops;
    while (match.hasNext()) {
        QString op = match.next().captured();
        int value = 0;
        if (op.mid(1) == "*") {
            value = INT_MAX;
        }
        else {
            value = op.mid(1).toInt();
        }
        if (value < 1) {
            continue;
        }
        if (op.startsWith("t")) {
            ops.append(QSharedPointer<BitOp>(new TakeOp(value)));
        }
        else if (op.startsWith("s")) {
            ops.append(QSharedPointer<BitOp>(new SkipOp(value)));
        }
        else if (op.startsWith("o")) {
            ops.append(QSharedPointer<BitOp>(new OneOp(value)));
        }
        else if (op.startsWith("z")) {
            ops.append(QSharedPointer<BitOp>(new ZeroOp(value)));
        }
        else if (op.startsWith("r")) {
            ops.append(QSharedPointer<BitOp>(new ReverseOp(value)));
        }
        else if (op.startsWith("i")) {
            ops.append(QSharedPointer<BitOp>(new InvertOp(value)));
        }
    }
    return ops;
}
