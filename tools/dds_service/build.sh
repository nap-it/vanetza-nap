ogp=$(pwd)
if [ $(uname -m) != "x86_64" ] ; then
    cd ../../pkg/mod/github.com/rticommunity/*/
    SRCDIR=$(pwd)
    export CGO_CFLAGS="-I${SRCDIR}/include -I${SRCDIR}/rticonnextdds-connector/include -DRTI_UNIX -DRTI_LINUX"
    export CGO_LDFLAGS="-L${SRCDIR}/rticonnextdds-connector/lib/linux-arm -lrtiddsconnector -ldl -lnsl -lm -lpthread -lrt"
    if [ $(uname -m) = "aarch64" ] ; then
    	export CGO_LDFLAGS="-L${SRCDIR}/rticonnextdds-connector/lib/linux-arm64 -lrtiddsconnector -ldl -lnsl -lm -lpthread -lrt"
    fi
    cd $ogp
fi
export GO111MODULE="on"
export GOMAXPROCS=1
go build main.go
