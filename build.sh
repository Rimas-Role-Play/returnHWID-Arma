echo "Start building extension secExt"
echo "secExt_x64.dll in progress..."
GOARCH=amd64 go build -o release/secExt_x64.dll -buildmode=c-shared .
echo "secExt_x64.dll builded"

echo "secExt.dll in progress..."
GOARCH=386 CGO_ENABLED=1 go build -o release/secExt.dll -buildmode=c-shared .
echo "secExt.dll builded"

rm release/*.h
echo "Auto-generated headers removed"

echo "Building done, find dll's in release folder"