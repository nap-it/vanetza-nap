ogp=$(pwd)
if [ $(uname -m) != "x86_64" ] ; then
    cd ../../pkg/mod/github.com/rticommunity/*/
    echo $(pwd)
    echo $(ls)
    SRCDIR=$(pwd)
    CGO_CFLAGS="-I${SRCDIR}/include -I${SRCDIR}/rticonnextdds-connector/include -DRTI_UNIX -DRTI_LINUX"
    CGO_LDFLAGS="-L${SRCDIR}/rticonnextdds-connector/lib/linux-arm -lrtiddsconnector -ldl -lnsl -lm -lpthread -lrt"
    if [ $(uname -m) = "aarch64" ] ; then
        rm -rf rticonnextdds-connector/lib/linux-arm
        mv rticonnextdds-connector/lib/linux-arm64 rticonnextdds-connector/lib/linux-arm
    fi
    cd $ogp
fi
GO111MODULE="on" go build -v main.go
