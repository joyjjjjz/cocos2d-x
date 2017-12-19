module("reload", package.seeall)

--重载代码，自定义loader必须放在最前面，切记
function Reload(szFileName)
	print("reload", szFileName)
	package.loaded[szFileName] = nil
	require( szFileName )

 --    local loader = package.loaders[1]
	-- local ret, err = pcall(loader, szFileName)
	-- print("reload return 1.1", szFileName, ret, err)
	-- if ret and type(err) == "function" then
	-- 	ret, err = pcall(err)
	-- 	print("reload return 1.2", szFileName, ret, err)
	-- 	if ret then
	-- 		return
	-- 	end
	-- end
	
	-- return err
end
