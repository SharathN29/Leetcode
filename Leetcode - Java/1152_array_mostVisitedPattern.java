// https://leetcode.com/problems/analyze-user-website-visit-pattern/

class Solution {

        static class Visit {
            String username;
            int timestamp;
            String website;

            public Visit(String username, int timestamp, String website) {
                this.username = username;
                this.timestamp = timestamp;
                this.website = website;
            }

            public Visit() {

            }
        }

    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website) {
        List<Visit> visitList = new ArrayList();
        for (int i = 0; i < username.length; i++) {
            visitList.add(new Visit(username[i], timestamp[i], website[i]));
        }

        Collections.sort(visitList, (v1, v2) -> v1.timestamp - v2.timestamp);

        Map<String, List<String>> userWebsiteMap = new HashMap();
        for (Visit v : visitList) {
            userWebsiteMap.putIfAbsent(v.username, new ArrayList());
            userWebsiteMap.get(v.username).add(v.website);
        }

        Map<List<String>, Integer> seqUserFreqMap = new HashMap();
        for (List<String> websiteList : userWebsiteMap.values()) {
            if (websiteList.size() < 3) continue;
            Set<List<String>> seqSet = generate3Seq(websiteList);
            for (List<String> seq : seqSet) {
                seqUserFreqMap.put(seq, seqUserFreqMap.getOrDefault(seq, 0) + 1);
            }
        }

        List<String> res = new ArrayList();
        int max = 0;

        for (Map.Entry<List<String>, Integer> entry : seqUserFreqMap.entrySet()) {
            if (entry.getValue() > max) {
                max = entry.getValue();
                res = entry.getKey();
            } else if (entry.getValue() == max) {
        		if (entry.getKey().toString().compareTo(res.toString()) < 0) {
        			res = entry.getKey();
        		}
        	}
        }
        return res;
    }

    private Set<List<String>> generate3Seq(List<String> websitesList) {
		Set<List<String>> setOfListSeq = new HashSet<>();
		for (int i = 0; i < websitesList.size(); i++) {
			for (int j = i + 1; j < websitesList.size(); j++) {
				for (int k = j + 1; k < websitesList.size(); k++) {
					List<String> list = new ArrayList<>();
					list.add(websitesList.get(i));
					list.add(websitesList.get(j));
					list.add(websitesList.get(k));
					setOfListSeq.add(list);
				}
			}
		}
		return setOfListSeq;
	}
}
