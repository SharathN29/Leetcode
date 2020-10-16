// https://leetcode.com/problems/making-file-names-unique/

class Solution {
    public String[] getFolderNames(String[] names) {
        Map<String, Integer> folderVersion = new HashMap();
        
        for (int i = 0; i < names.length; i++) {
            names[i] = getVersion(folderVersion, names[i]);
        }
        
        return names; 
    }
    
    private String getVersion (Map<String, Integer> folderVersion, String name) {
        if (folderVersion.containsKey(name)) {
            int version = folderVersion.get(name) + 1;
            
            while (folderVersion.containsKey(name + "(" + version + ")")) {
                version++;
            }
            
            folderVersion.put(name, version);
            name = getVersion(folderVersion, name + "(" + version + ")" );
        } else {
            folderVersion.put(name, 0);
        }
        
        return name; 
    }
}