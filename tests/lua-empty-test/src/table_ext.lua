module("table", package.seeall)
--[[
说明：
	反转数组的原始排列顺序，返回新建的table,不改变源table
返回值：
	table 新建的table
参数：
	t table 必须是数组
]]
function revert(t)
	local len = #t 
	local t2 = {}
	for i = 1, len do
		t2[len + 1 - i] = t[i]
	end
	return t2
end

--[[
说明：
	浅层次克隆一个hash表，并不递归克隆
返回值：
	table 新建的table
参数：
	t table 源hash表
]]
function clone(t)
	local u = setmetatable({}, getmetatable(t))
	for i, v in pairs(t) do
		u[i] = v
	end
	return u
end

--[[
说明：
	递归深度克隆一个hash表
返回值：
	table 新建的table
参数：
	t table 源hash表
]]
function deepclone(t)
	local r = {}
	local index = {[t] = r}

	local function clone_(dst, src)
		for i, v in pairs(src) do
			if type(v) == "table" then
				if not index[v] then
					index[v] = {}
					dst[i] = clone_(index[v], v)
				else
					dst[i] = index[v]
				end
			else
				dst[i] = v
			end
		end

		setmetatable(dst, getmetatable(src))
		return dst
	end

	return clone_(r, t)
end

function append(t1, t2)
	for _, v in ipairs(t2) do
		table.insert(t1, v)
	end
	return t1
end

function size(t)
	local n = 0
	for _, v in pairs(t) do
		n = n + 1
	end
	return n
end

function convertnumber(t)
	local ret = {}
	for i,v in pairs(t) do
		ret[i] = tonumber(v)
	end
	return ret
end

function suffle(t)
	local len = #t
	for i, v in ipairs(t) do
		local index = random.IRandom(1, len)
		t[i], t[index] = t[index], t[i]
	end
end

function find(t, value)
	for k, v in ipairs(t) do
		if v == value then
			return true, k
		end
	end
	return false, 0
end

function GetSortedKey(tSrcTable, fSortFun)
    if not fSortFun then
        fSortFun = function (a , b)
            if a < b then 
                return true
            end
        end
    end

    local tKey = {}
    for key, _ in pairs(tSrcTable) do
        table.insert(tKey, key)
    end
    table.sort(tKey, fSortFun)
    return tKey
end

--[[
	有序迭代器：根据table key的次序来进行遍历。可选参数fSortFun用于指定某种特殊次序。
	以下函数先将key排序到一个数组中，然后迭代这个数组，且每步都返回原table中的key和value。
--]]
function PairsByKeys(tSrc, fSortFun)
    local tKey = {}
    for n in pairs(tSrc) do
        tKey[#tKey + 1] = n
    end
    table.sort(tKey, fSortFun)

    local i = 0 --迭代器变量
    return function () --迭代器函数
        i = i + 1
        return tKey[i], tSrc[tKey[i]]
    end
end

function min(t)
	local m = t[1]
	for _, v in ipairs(t) do
		if v < m then
			m = v
		end
	end
	return m
end

function max(t)
	local m = t[1]
	for _, v in ipairs(t) do
		if v > m then
			m = v
		end
	end
	return m
end

function removevalue(t, value)
	for k, v in ipairs(t) do
		if v == value then
			table.remove(t, k)
			break
		end
	end
	return t
end

function MaxValue(t)
    local m = 0
    for _, v in pairs(t) do
        if v > m then
            m = v
        end
    end
    return m
end

function FindKey(t, value)
    for k, v in pairs(t) do
        if v == value then
            return true, k
        end
    end
    return false, 0
end

function ClonePart(t, nCount)
    local tRt = {}
    if size(t) <= nCount then
        tRt = clone(t)
    else
        for i=1, nCount do
            insert(tRt, t[i])         
        end
    end
    return tRt
end