package graduation.design.mapper;

import java.util.*;
import org.apache.ibatis.annotations.Param;
import graduation.design.model.BaoxiaoStatus;

public interface BaoxiaoStatusMapper {

	public void insertObject(BaoxiaoStatus baoxiaoStatus);

	public void deleteObject(int id);

	public void updateObject(BaoxiaoStatus baoxiaoStatus);

	public BaoxiaoStatus selectObject(int id);

	public List<BaoxiaoStatus> getObjectList(@Param("field") String field,
			@Param("fieldValue") String fieldValue);

}
