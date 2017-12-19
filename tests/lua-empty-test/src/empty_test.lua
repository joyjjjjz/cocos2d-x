local loader = package.loaders[1]
-- local ret, err = pcall(loader, szFileName)
-- print("reload return 1.2", szFileName, ret, err)
if ret and type(err) == "function" then
    ret, err = pcall(err)
    print("reload return 1.2", szFileName, ret, err)
    if ret then
        return
    end
end

for k,v in paris(package.loaders) do
    print(k, v)
end